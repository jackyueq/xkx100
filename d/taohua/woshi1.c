// Room: /d/taohua/woshi1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���߽���һ���Է���һ���������޵������˱Ƕ������ٽ��黭����
��ǽ�ϡ�����ɴ�֣������⡣С������Ҥ����ƿ�ڵ��һ�����ʢ����
����һ�Ŵ�����ͷ���������Ʊ���
LONG );
	set("exits", ([
		"west" : __DIR__"neishi1",
	]));
	set("objects", ([
		CLASS_D("taohua")+"/rong" : 1,
		__DIR__"npc/binu" : 2,
	]) );
	set("coor/x", 9010);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}