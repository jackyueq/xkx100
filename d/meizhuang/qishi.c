// /d/meizhuang/qishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
������Ƕ�ׯ���ڰ��ӵ������ˣ�����������ʯ�ʣ�һ��ʯ����ʯ
�����úڰ��ӵ�ָ�������ݺ�žŰ�ʮһ����������˼򵥵ķ�������
�������ɵ������⣬ʲô��û�У�������˫������ʱ���ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang2",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/zi" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
