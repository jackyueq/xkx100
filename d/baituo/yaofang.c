// Room: /d/baituo/yaofang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","ҩ��");
	set("long", @LONG
�����Ǽ�ҩ������ǽ����һֻ��ҩ���������������ӣ��ϱ߰���
����ҩ�õ�ƿƿ�޹ޡ�����һ��ҩƿ(bottle)��ֻװ����ˮ����ҩʦ��
λС����������﷢������֪����ʲô�����������ɵĳ��ȡ�
LONG	);
	set("exits",([
		"north" : __DIR__"changlang",
	]));
	set("no_fight", 1);
	set("item_desc",([
		"bottle" : "ҩ�������ű�ǩ�����ߵ��ࡻ�������Ʒ������������Ч����ѡ�\n",
	]));
	set("objects",([
//		__DIR__"obj/wan" :1,
		__DIR__"npc/xiaoqing" : 1,
	]));
	set("coor/x", -50020);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
