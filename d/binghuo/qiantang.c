// Room: /binghuo/qiantang.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "Ǯ������");
	set("long", @LONG
Ǯ����������������תһ�����䣬Ȼ��ֱ�������ô��͸�����
�಻�������������������ϵ��һ�ұ���(zhou)���������з緫����
ͷ������յ��ɴ��������ɴ���£�һ����Ů������ͷ�����������ӡ�
LONG );
	set("outdoors", "wangpan");
	set("no_clean_up", 0);
	set("item_desc", ([
		"zhou" : "һ��С�ۣ�������ȥ(enter)������\n",
	]));
	set("exits", ([
		"westup" : "/d/hangzhou/qiantang",
	]));
	set("coor/x", 4080);
	set("coor/y", -1800);
	set("coor/z", -10);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="zhou" )
        {
               message("vision",
                        me->name() + "�����Ṧ��һ��������С�ۡ�",
                        environment(me), ({me}) );
               me->move(__DIR__"zhou");
               message("vision",
                        me->name() + "�Ӱ���Ծ��������\n",
                        environment(me), ({me}) );
                        return 1;
        }
        else  return notify_fail("���뵽��ȥ��\n");
}