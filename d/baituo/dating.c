// Room: /d/baituo/dating.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ǡ�����ɽׯ���Ĵ������ڲ����輫������������һ�ź�ɫ̴ľ
����������·��ž����Ļ�ƿ��һЩ���Ĵ������ıڹ������ҵ��ֻ���
LONG	);
	set("valid_startroom",1);
	set("exits", ([
		"north" : __DIR__"liangong",
		"southdown" : __DIR__"kongdi",
	]));
	set("objects",([
		CLASS_D("baituo")+"/ouyangfeng" : 1,
		__DIR__"npc/yahuan" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20030);
	set("coor/z", 30);
	setup();
	"/clone/board/baituo_b"->foo();
	replace_program(ROOM);
}
