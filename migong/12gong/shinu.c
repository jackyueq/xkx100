// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "��������Ů��");
        set ("long", @LONG
   !$$$$$!:i$$$$$W: :W$$$$Wu:  uWW$WWu
    ~$$$$W$*" ~$$$$W$#~ !$$$$W$$#*$$$$:
     $$$$$~    $$$$$~    $$$$$?~  !$$$
     $$$$!     $$$$$     $$$$!    W$#
    ~$$$$!     $$$$!     $$$$~  u$*~      ���������񻰣���Ů��������˼��ʫ
     $$$$!     $$$$!     $$$$ :W$"   (Astraes)��Ϊ��������غ�ϣ��˿Ů���
     $$$$~     $$$$H     $$$$W$#~  Ů����������Ů�񡣻ƽ�ʱ��ĩ�ڣ����ഥ��
     $$$$      $$$$!     $$$$#~ ��������Ǵ�ŭ֮�»ص���ͥ��
    ~$$$$!     $$$$H    :$$$$
    !$$$$!     $$$$!  :W$$$$$
    !$$$$!    !$$$$R i$$~$$$$
   ~**###*~  ~#**#*#W$#  $$$!
                    $$  X$$!
                    $W:W$$~
                    *$$*#

LONG);


        set("exits", ([
        "westup"    :       __DIR__"sn2tc1",
        "northdown"  :       __DIR__"sz2sn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shinu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shi nu") && dir == "westup" )
        return notify_fail("�ն�÷˹��Ц���ȹ��������˵��\n");
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
