// Room: /d/lingzhou/xiaolou.c

inherit ROOM;

void create()
{
	set("short", "С¥");
	set("long", @LONG
����һ������¥��ľ�ƽ������˵��ǽ�̻Իͣ�������ǧ��������
��ס������ײ���һ����س��������ɫ��Բ������¥�и�С��̨��
��¥¥�������������������������⣬�ͻʳǴ��Ľ�ͬΪȫ�Ƕ���
�����Ľ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"jjdayuan",
	]));
	set("objects", ([ /* sizeof() == 2 */
		__DIR__"npc/yahuan" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -17950);
	set("coor/y", 32040);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
