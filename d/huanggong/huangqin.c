// Room: /d/huanggong/huangqin.c

inherit ROOM;

void create()
{
	set("short", "��ڵ�");
	set("long", @LONG
���ǻ��Ϸ���ͼ�麲ī�Լ���͢�峼ֵ�����ڵǬ¡������ʱ
���ڴ˶��顣�˴��������࣬��Ϊ�ڸ��࿯�ĸ������顣�����̷�����
���졣ÿ������ڴ����һ�Σ��ʳơ����󡱡�������������ˡ�Ҳ
��Դ�ڴˡ�����ʻ����ߣ����������ơ��������򡰹������������
�ڵ�������ֳơ���ڵ������
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"qianqinggong",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/wenyoufang" : 1,
	]));

	set("coor/x", -210);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}