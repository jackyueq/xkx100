// Room: /d/mobei/boershu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "������Ӫ��");
	set("long", @LONG
�������������ˣ�����Ϊ�ɹ����е�Ӣ�ۣ�����ʱ��ͬ��ľ��һ��
׷ɱ���������Ӫ����ֻ�Ǽ���ձ�����ѷţ�һ�˳�ǹ��һ����̥����
��Ӿź�������������������ͨ���������֮�࣬���˿ɼ���
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boerhu" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"road3",
	]));

	set("coor/x", -220);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
