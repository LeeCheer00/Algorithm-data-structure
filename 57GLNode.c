typedef struct GLNode{
        int tag;//标志域
        union{
                char atom;//原子结点的值域
                struct{
                        struct GLNode * hp, *tp;

                }ptr;//字表结点的指针域，hp指向表头，tp指向表尾
        };
}*Glist;



Glist creatGlist (Glist C) {
        //广义表C
        C=(Glist)malloc(sizeof(Glist));
        C->tag=1;
        //表头原子‘a’
        C->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.hp->tag=0;
        C->ptr.hp->atom='a';
        //表尾字表（b,c,d）,是一个整体
        C->ptr.tp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->tag=1;
        C->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.tp=NULL;
        //开始存放下一个数据元素（b,c,d）,表头为'b',表尾部为（c,d）
        C->ptr.tp->ptr.hp->tag=1;
        C->ptr.tp->ptr.hp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.hp->ptr.hp->tag=0;
        C->ptr.tp->ptr.hp->ptr.hp->atom='b';
        C->ptr.tp->ptr.hp->ptr.tp=(Glist)malloc(sizeof(Glist));
        //存放字表（c,d),表头为C,表尾为d
        C->ptr.tp->ptr.hp->ptr.tp->tag=1;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->tag=0;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.hp->atom='c';
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp=(Glist)malloc(sizeof(Glist));
        //存放表尾d
        C->ptr.tp->ptr.hp->ptr.tp->tag=1;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->hp=(Glist)malloc(sizeof(Glist));
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->hp->tag=0;
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp->atom='d';
        C->ptr.tp->ptr.hp->ptr.tp->ptr.tp->ptr.hp=NULL;
        return C;


}
