// Room: /d/jiaxing/jnroad2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����ڽ��ϵ�һ��ɽ·�ϣ�����ݺ�ɲݳ���ʱֵ���գ�·�Ե�ɽ��
�Ͽ����˽��ɫ���Ͳ˻��������ǽ������Ǽ��ˡ����߾�������������
�ݸ��ˡ�
LONG );
	set("exits", ([
		"south" : __DIR__"jnroad3",
		"north" : __DIR__"jnroad1",
		"east"  : __DIR__"jiaxing",
		"west"  : "/d/suzhou/dongmen",
	]));
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
	set("coor/x", 1000);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}