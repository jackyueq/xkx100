// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "�ڰ˹���Ы��");
        set ("long",
             @LONG
      iWWW:  :W$WW   :xW$Wx
     W$$$$ :$$$$$$X u$$$$$$
    W$$$$$W$#~$$$$$$$?~$$$$!       �����������Ы�������ĵص�������������ŷ��
   X$?$$$$$?  M$$$$#   $$$$~ ���� Orion,����������������ˣ��ữΪ�Ի���
  H$! $$$$!   8$$$$    $$$$! ����������һ�Σ���Ыʩ�Ŷ�������������̫��
  ~~  $$$$    8$$$8    $$$$~ ���������ķƶ٣���ʹ������л��ᷢ���׵�
      $$$$~   8$$$8    $$$$! ���������е�̫�������١�
      $$$$    M$$$8    $$$$!
      $$$$    8$$$8    $$$$~
      $$$$    M$$$8    $$$$!       Xi
      $$$$    8$$$8    $$$$!      X$R
      $$$$    R$$$8    $$$$~    xW$$!
      $$$$    #$$$M    $$$$   W$$$$$
                       $$$$     $$$8
                       $$$$!  :$$  $
                       ~#$$$oW$#

LONG);
        set("exits", ([
        "eastup"    :       __DIR__"tx2rm1",
        "southdown"  :       __DIR__"tc2tx2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/tianxie" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("tian xie") && dir == "eastup" )
        return notify_fail("����˹Ц��:�ȹ��������˵��\n");
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
