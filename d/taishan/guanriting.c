// Room: /d/taishan/guanriting.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
���������ǹ���ͤ�����ն�����̩ɽ�����˵���ۡ���������
�����ʣ��������ԣ�����һ�߳����ɻҰ��䵭�ƣ����ɵ��Ʊ���ٺ졣
�̶�������ƶ���Ͻ��ӣ�˲Ϣ��䡣�����ϼ���ƽ���ϵ�ãã����
��Ϊһ�壬��ϼ������ӳ������է����������̰��£����϶�ֹ������
��㱣��·��ж����������������ƿ���Ļ��ȽȽ��������Ʈ���ŵĹ�
�ơ���̼䣬������䣬Ⱥ�御Ⱦ��
LONG );
	set("exits", ([
		"west" : __DIR__"yuhuang",
	]));
	set("objects", ([
		"/d/village/npc/seller" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
