// /d/meizhuang/chufang.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��˳����ζ�ߵ���÷ׯ�ĳ�����һλ��ʦ��վ����̨����Ц���е�
�����㣬����������һ�����ף������İѹ������ŵ�һ���ʳ����ȣ�
÷ׯ�ĵ�����������ˣ��͵�����������λ��ʦ�ܲ��ܳԷ���һ����˵��
���Ƕ������⵽�ܾ��ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang3",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/chushi" : 1,
	]));

	set("coor/x", 3500);
	set("coor/y", -1350);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
