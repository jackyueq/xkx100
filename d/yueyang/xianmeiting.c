// Room: /d/yueyang/xianmeiting.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "��÷ͤ");
	set("long", @LONG
��÷ͤλ������¥�����棬�ഫ�������������������¥�ھ�ػ�
ʱ�����һ��ʯ�壬ʯ��������һ����һ֦��÷���������ֶ�ʮ��
�࣬����Ծ������ɼ�������������Ϊ���ɼ�������һСͤ����ʯ����
����Ϊ���
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"yueyanglou1",
	]));
	set("coor/x", -1450);
	set("coor/y", -2270);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
