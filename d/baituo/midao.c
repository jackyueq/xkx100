// Room: /d/baituo/midao.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","�ܵ�");
	set("long", @LONG
��������ڵ��ܵ����������ɽ����Ϊ��ֱ����ԭ������ġ�
LONG	);
	set("exits" , ([
		"east" : "/d/city/ganquanjie",
	]));
	set("objects",([
		__DIR__"obj/shenshe" : 1 ,
	]));
	set("coor/x", -50020);
	set("coor/y", 20060);
	set("coor/z", 20);
	setup();
}
void init()
{
	add_action("do_get", "get");
}
int do_get(string arg)
{

	object me = this_player();
	object ob;
	if ((arg != "shenshe") || !arg)
		return notify_fail("��Ҫ��ʲô��\n");
	if(!objectp(ob=present("shenshe",environment(me))))
		return notify_fail("����û�С���·���ߡ�.\n");
	if(me->query("family/family_name") != "����ɽ��")
		return notify_fail("����ֻ�а���ɽ�ɵ��Ӳ���ʹ���ġ���·���ߡ���\n");
	ob->move(me);
	message_vision("$N������·���ߡ����ڻ��\n",me);
	return 1;
}
