// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "��һ��������");
        set ("long", @LONG

    :iW$$$$Wi:          :uWW$$$WWx
  :W$$$####$$$$W:    :i$$$$*###*$$$x
  $$$?      ~#$$$X  :$$$#~      ~$$$
  $$$          $$$X:$$$~         8$$!
  #$$i  ~      ~$$$$$$!   :   ~ x$$$
   #$$$WWi$$    ?$$$$$    8$WiW$$$#
     ~""""      ~$$$$!      """""
                 $$$$~  ������˹(Phrixus)���β���(Nepele)֮�ӣ�
                 $$$$~���ϼ��۱��ŵ١� (Biadice)�Ĳ���֮ԩ�������д����̣�
                 $$$$:����֮ǰһֻ��ɫ�Ĺ���ʱ���������ú���(Helle) һ
                 $$$$~���߲��ҵ��ǣ�������ʤ������һʱ�ۻ������򱳣�
                ~$$$$ ������˹��Ȼ��ȣ����������׸���˹��������˹��
                 ?$$? ��������Ϊ���ϵ���������������Ϊ�˶�ȡ��������
                      ë����չ����һ�ξ��ʵ�ð�չ��¡�

LONG);


        set("exits", ([
        "northup"    :       __DIR__"by2jn1",
            "eastdown"  :       __DIR__"toby2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/baiyang" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}
int valid_leave(object me, string dir)
{
        if ( present("bai yang") && dir == "northup" )
        return notify_fail("����˹��Цһ�����ȹ��������˵��\n");
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
