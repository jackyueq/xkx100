// Room: /d/kunlun/xsxiepo2.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "ѩɽб��");
	set("long", @LONG
���ֽ��ŵأ�����ѩɽб�£�һ��һ������������֮����ȥ������
�ͱڱ��ͼ��������϶����ѩ�����ǻ����ޱȣ�һ��С����Ử����
LONG);
	set("exits",([
		"east" : __DIR__"pingtai",
	]));
	set("outdoors", "hongmei");
	set("no_clean_up", 0);
	set("coor/x", -100010);
	set("coor/y", 20010);
	set("coor/z", 40);
	setup();
}
void init()
{
	add_action("do_pa","pa");
}
int do_pa(string arg)
{
	object me;
	me=this_player();
	if (!(arg||arg=="east"||arg=="west")) return 0;
	if (arg=="west")
	{
		message("vision",me->name()+"��������ȥ��\n",environment(me),me);
		write("����������ȥ��\n");
		me->move(__DIR__"xsxiepo1");
		message("vision",me->name()+"���˹�����\n",environment(me),me);
		return 1;
	}
	return 1;
}

