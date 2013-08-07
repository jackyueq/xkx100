// Room: /d/yueyang/gaibangyuan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
Ժ��������ưܣ��̵ص���ש�������ѣ�Χǽ����ƬҲ�ǲ�ȱ��ȫ
�ġ�ؤ���������£��ܶ�ȴ��˲����ۣ�Ҳ����ؤ����ɫ��������һ��
���ţ����ߵĴ��ݺڹ�¡�˵ġ���������ķ��䴰������֩����������
����һ�Ѱѵ�é�ݣ�������ؤ��������Ϣ������Ժ��������һ�۾�̨��
����̦�Ĺž�(jing)�����ڵ��Ǻܹ⻬���ƺ��������ھ��г��롣
LONG );
	set("outdoors", "yueyang");
	set("exits", ([
		"north" : __DIR__"gaibangtang",
		"south" : __DIR__"gaibanggate",
	]));
	set("item_desc", ([
		"jing"  : "һ������ˮ������\n",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1420);
	set("coor/y", -2250);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;

	if( arg=="jing" )
	{
		if((fam = me->query("family")) && fam["family_name"] == "ؤ��" )
		{
			message("vision", me->name() + "����ؤ�����ǹ���һ����������������ȥ��\n", environment(me), ({me}) );
			me->move("/d/gaibang/underyy");
                	message("vision", me->name() + "�Ӿ������˽�����\n", environment(me), ({me}) );
			return 1;
		}
		else return notify_fail("��ôС�ľ�������ý�ȥ��\n");
	}
}	

