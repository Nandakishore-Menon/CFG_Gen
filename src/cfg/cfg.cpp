#include "include/cfg/cfg.hpp"

int CFG::idIncrement() {
    return id_count++;
}

void CFG::idReset() {
    id_count = 1;
}

CFG::CFG(Node* head) {
    idReset();
    cdg = head;
}

CfgNode* CFG::CFG_gen(CfgNode* head, CfgNode* curr, Node* curr_cdg) {
    if(curr_cdg->child != NULL) {
        CfgNode* temp = new CfgNode(idIncrement(), curr_cdg->child);
        curr->next = temp;
        CFG_gen(curr, temp, curr_cdg->child);
    }
    while (curr_cdg->next != NULL) {
        CfgNode* temp = new CfgNode(idIncrement(), curr_cdg->next);
        curr->next=temp;
        curr = temp;
        curr_cdg = curr_cdg->next;
        if(curr_cdg->child != NULL) {
            CfgNode* temp = new CfgNode(idIncrement(), curr_cdg->child);
            curr->next = temp;
            CFG_gen(curr, temp, curr_cdg->child);
        }
        if(curr_cdg != NULL && curr_cdg->line_type == CLOSEBRACE) {
            CfgNode* temp = new CfgNode(idIncrement(), curr_cdg);
            curr->next = temp;
            curr_cdg = curr_cdg->next;
            break;
        }
    }
    if(head->line_type == FOR || head->line_type == WHILE) {
        curr->loopback = head;
        curr = head;
    }
    return head;
}