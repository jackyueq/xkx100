// Room: /d/huangshan/yixian.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "һ����");
	set("long", @LONG
�춼������Խ���������Ժȥ����С���£������ɣ�����ش�ֱ��
ϵ�绯�ġ�һ���족������ʮ���������ߴ���ʮ���׵�ʯ�ڽ���������
���������ף�խ��ֻ�а��ף��������գ�����һ�ߡ�һ������������
����Ժ�ˡ�
LONG
	);
	set("exits", ([ 
		"west"    : __DIR__"wenzhu",
		"southup" : __DIR__"tiandu",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
