// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "�ھŹ�������");
        set ("long",
             @LONG
                         :$?
                          :X$$?
                       :uW$$$M
                    :!M$#$$$$~ ���������ֵ��ǰ��˰������̬�����ж��������
                       :W$M$? ˫����Ŀ���Ǹ���������֪��  ҽ����ѧ�ߡ�����ϣ
                     :X$# ~R~ ��������Ӣ�۽��� (Jason)��������˹ (Achilles)��
                    :W$"   ~ ����˹   (Aeneas)�ĸ����ߡ���˵���ǿ�����˹(Cron
                   x$M  us)������� (Philyra)֮�� ,Ҳ����˹�ĸ��ס��������ܾ�
                 :H$"  ���ᣬ���Լ���Ϊ������ĸ������ܲ��˶��Ӱ��˰����
                x$$~   ��ģ����������һ����������
    :::: :: : :W$?:: : :
    $$$$$$$$$$$$$$$$$$$$?
    M$$$$$$$$$$$$$$$$$$$?~
    ~ ~ ~ :$$~ ~  ~    ~
         X$?~
         ~~~                                 

LONG);
        set("exits", ([
        "northup"    :       __DIR__"rm2mj1",
        "eastdown"  :       __DIR__"tx2rm2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/renma" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("ren ma") && dir == "northup" )
        return notify_fail("��˹Ц��:�ȹ��������˵��\n");
        return ::valid_leave(me, dir);
}
void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "hit") return 1;if (verb == "fight") return 1;if (verb == "touxi") return 1;if (verb == "exert roar") return 1;
    return 0;
}
