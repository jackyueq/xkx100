// Room: /d/nanshaolin/gulou1.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "��¥һ��");
	set("long", @LONG
��������¥�ĵײ㣬һ���������ǽ�ϵĻ�ש��϶��͸���������
��ש����Ͷ�±��µĹ�Ӱ����ͬһ����������ơ����Ͽ���������ľ¥
�����ƶ��ϣ��ƺ����޾�ͷ��ǽ�ǣ��ݼ����൱�ྻ������������ɮ��
��ɨ��
LONG );
	set("exits", ([
		"up"  : __DIR__"gulou2",
		"out" : __DIR__"gulou",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1800);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



