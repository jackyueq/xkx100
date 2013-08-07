// Room: /d/baituo/chufang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long", @LONG
���Ǽ���ĳ�������ʦ����չʾ���Ե���⿾��������������
�����˴������εĲ��㡣ǽ������һ����Ŀ������(note)��
LONG	);
	set("exits",([
		"west" : __DIR__"huayuan",
		"east" : __DIR__"chaifang",
	]));
	set("item_desc",([
		"note" : "����������С����ÿ��һ���񣬸����������ӡ�\n",
	]));
	set("objects",([
		__DIR__"npc/feifei" : 1,
		__DIR__"obj/doujiang" : random(5),
		__DIR__"obj/cake"  : random(3),
	]));
	set("no_fight", "1");
	set("no_beg", "1");
	set("coor/x", -50000);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
}
int valid_leave(object me, string dir)
{
	if (( present("jiang", me) || present("cake", me)) &&
		objectp(present("fei fei", environment(me))) )
		return notify_fail("�ʷ�һ��קס������죬�ż��ؽе������˲��ܴ���ȥ����������Ѿ���\n���ˡ�\n");
	return ::valid_leave(me, dir);
}
