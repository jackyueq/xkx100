// Room: /d/huanggong/qinandian.c
inherit ROOM;

void create()
{
	set("short", "�հ���");
	set("long", @LONG
�հ���λ������԰��, �Ϊƽ������ʽ, ��Χ�к�����ʯ����. 
���ڹ���������, ��������ؼ�ɽ, �滨����. ���ߴ�������԰��ʯ
���͵Ķ���ɽ, ���ǻʹ��ı�����������.
LONG
	);
	set("exits", ([
		"north"     : __DIR__"shenwumen",
		"south"     : __DIR__"yuhuayuan2",
	]));
	set("coor/x", -200);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}