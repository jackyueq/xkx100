// Room: /d/quanzhou/xiyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "ϷԺ");
	set("long", @LONG
�������Ϸ�Ϸ�����ģ�����˷���Ϸ��ÿ�춼ӿ��˵�һ��Ϊ�졣
ϷԺ��Ϸ�ַ��࣬��Ŀ���ʡ�������������԰Ϸ������ľż���߼�Ϸ��
�����ķ������������
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"zhaiqu2",
		"east"      : __DIR__"zhaiqu1",
	]));
	set("coor/x", 1830);
	set("coor/y", -6540);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
