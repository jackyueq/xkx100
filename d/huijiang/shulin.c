// Room: /d/huijiang/shulin.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���ߵ������ֲ���ï�ܣ�ֻ��ϡ��ļ��ã�Զ����ɽ�ϸ����Ű�ѩ��
��ͬ���ϰ�ɫ���Ʋʡ���������໥ײ���Ķ��������Դ���������Ұ��
����ζ�ӽ���������������������ǳǳ��һ�㡣
LONG );
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 3 */
		"west"      : __DIR__"buluo",
		"south"     : __DIR__"shulin3",
		"southeast" : __DIR__"byriver1",
	]));
	set("objects", ([ /* sizeof() == 3 */
		CLASS_D("honghua")+"/yu-yutong" : 1,
	]));
	set("coor/x", -50040);
	set("coor/y", 9040);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
