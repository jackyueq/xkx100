// /kaifeng/tieta.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
������ʮ���ף��˽�ʮ���㡣����˵�Ϊ�ο����£�������������
������������Ϊ��ɫ����ש���ɻ�˽����������׳���Ϊ������������
����������ΰ��ש�����Է��졢�����ּ�����ʮ��ͼ��������������
LONG);
	set("outdoors", "kaifeng");
	set("exits", ([
		"west" : __DIR__"jieyin",
		"east" : __DIR__"eroad3",
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
