// liangong.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���������е�һ��ʯ�ݣ������Ե�ʲô�徻�ͼ��ӣ������г���һ
�������⣬��û��ʲô�ر�İ�������������ܵ��κζ�����ɧ�ţ�
�Ǹ������ڹ��ĺõط���
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao4",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("xiaoyao")+"/fanbailing" : 1,
	]));
	set("coor/x", 90);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}