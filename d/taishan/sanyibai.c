// Room: /d/taishan/sanyibai.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����¥λ�ں��Ź�����¥ǰ�йŰ����꣬ͦ�β��У��Դ����ƣ���
�顰����ء�����ǰ�����⡰�µ��ɾ��������ж���������ʯ�꣬�׳�
�궴��
LONG );
	set("exits", ([
		"north"     : __DIR__"wanxianlou",
		"southdown" : __DIR__"yitian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 570);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
