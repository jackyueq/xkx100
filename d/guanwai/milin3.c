// /guanwai/milin3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����һƬï�ܵ����֣����ҵ���������б��ɽ���ϡ�ÿ����������
���ı���ϸ���ߴ�ʮ���ɡ�����֦��Ҷ�ܣ��������ȫ��ס���������
�Ե���Щ�谵����ľ֮�䳤�źܶ��ľ�Ӳݣ�ʹ���ߺܼ��ѣ���˵�˲�
����������Щ�Ӳ�֮�С�
LONG );
	set("exits", ([
		"northdown"  : __DIR__"milin2",
		"eastup"     : __DIR__"heifengkou",
	]));
	set("count", 2);
	set("no_clean_up", 0);
	set("outdoors", "changbai");
	set("coor/x", 6160);
	set("coor/y", 5200);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_dig","dig");
}
int do_dig()
{
	object ob,me;
	me = this_player();

	if (query("count") < 1)
	{
		message_vision("$N����ϣ�����˰��죬��˵ǧ���˲��ˣ�������Ķ�û�С�\n",me);
		return 1;
	}
	add("count", -1);
	message_vision("$N�е��ڵ���ʲô������æ�ú��߱��ϣ������Ϳ��Աߵ�ϸ����������Ĩ��������������������ڲ����ĳ����˲��ˡ�\n", me);
	ob = new("/clone/medicine/vegetable/renshen");
	ob->move(me);
	return 1;
}