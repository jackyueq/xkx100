// Room: /d/lingzhou/zhaiyuan.c

inherit ROOM;

void create()
{
	set("short", "��լԺ");
	set("long", @LONG
���Ǹ������Ժ�ӣ�һɫ��ש�̵أ������Ƕ����᷿��ס��Ѿ�ߺ�
���ӣ����������������С¥��Ѿ���ǽ�����������æµ��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/yahuan" : 2,
	]));
	set("cost", 1);
	set("outdoors", "lingzhou");
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"jjdayuan",
	]));
	set("coor/x", -17940);
	set("coor/y", 32050);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
