// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "��ʮ����˫����");
        set ("long",             @LONG
   ~?$$$$W:                x$$$$#
      ?$$$$u :           :$$$$#
        "$$$W           :$$$#~
          #$$$:        W$$$~
           #$$$       !$$$!                                             
            $$$X      $$$!   ά��˹���������һ�α�����̩�壨 Typhon����
            M$$$:: ::H$$$  ׷��˫˫�����׷����׺��У�����Ϊ�����ߡ�����
            !$$$$$$$$$$$$  ���� Mineave���ŵ��ȵı��������㻯Ϊ�ǳ������
            !$$$"#"""$$$8  �ϣ��Լ�������¡�
            H$$$     ?$$$
            $$$?     ~$$$!
           W$$$       M$$$:
          W$$$~        #$$$:
        :$$$#           ?$$$x:
      xW$$$?             "$$$$u
    !R$$$#                 "*$$$!
LONG);
        set("exits", ([
        "north"    :       __DIR__"topalace1",
        "southdown"  :       __DIR__"bp2sy2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangyu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shuang yu") && dir == "north" )
        return notify_fail("��ʿ��Ц��:�ȹ��������˵��\n");
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
