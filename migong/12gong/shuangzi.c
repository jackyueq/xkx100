// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "������˫����");
        set ("long", @LONG
  W$$Wu                :uW$$W
  $$ "*$i             W$#~ $$
   #$x ~$W:          $$~ x$#
    ~*$W$$$:       !$$$i$*~
       !$$$$WWiWiWW$$$$~
        $$$$$~~~~~$$$$W~
        $$$$$!   !$$$$8     �񻰹����м����Ҳ�����˫�������йصĴ�˵���ڰ���
        $$$$$W   8$$$$8  ��������Ϊ�������ǡ����������������������������ǿ�
        $$$$$$  ~$$$$$$  ˹�� (Castor)�Ͳ�����˹ (Pollux)�����������������⻹
        $$$$$$   $$$$$8  ���������ƣ��ֱ�Ϊ������˹ (Hecules)�������� (Apollo)
        $$$$$$   $$$$$8  ���������� (Tritolemus)����ѷ (Iasion)�������˹�����
        $$$$$M   $$$$$8  ��������Ϊ��ͯ������һ�㳣���ĳ�������
        $$$$$!   !$$$$8
        $$$$$xuuu:$$$$8
      :u$$$$*######$$$$u:
    x$$#$$$~       ~$$$#$W::
  :$$~ x$#           *$: ~$W
 !$$ uW$"             "$iu $$
 ~#**#~~               ~~#**#

LONG);


        set("exits", ([
        "southup"    :       __DIR__"sz2jx1",
        "westdown"  :       __DIR__"jn2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangzi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("shuang zi") && dir == "southup" )
        return notify_fail("�ն�÷˹��Ц:�ȹ��������˵��\n");
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
