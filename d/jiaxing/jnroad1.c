// Room: /d/jiaxing/jnroad1.c
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
		"northwest" : "/d/taishan/yidao1",
		"south"     : __DIR__"jnroad2",
	]));
	set("outdoors", "jiangnan");
	set("no_clean_up", 0);
	set("coor/x", 1000);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}