// Room: /d/jiaxing/jnroad3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����ڽ��ϵ�һ��ɽ·�ϣ�����ݺ�ɲݳ���ʱֵ���գ�·�Ե�ɽ��
�Ͽ����˽��ɫ���Ͳ˻���
LONG );
	set("exits", ([
		"north" : __DIR__"jnroad2",
		"east"  : __DIR__"jnroad4",
	]));

	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("coor/x", 1000);
	set("coor/y", -2000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}