// Room: /d/taishan/taohua.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "�һ���");
	set("long", @LONG
�һ���������ӣ��԰���������̣���ӣ�������ף�ʯ�϶��̦��ɽ
�»����䣬ɽͷ��δ����������ʯƺ���������µ�崣�Ϫˮ����������
����ļ���ȥ����Ϊ�٣���Ϊ̶����Ǳ������Ϊ���̳أ�����Ȫ�塣
�����ҡ�ӣ���ޣ�Ψ������ȣ����ּа���ʯϿ��������ˮ������
LONG );
	set("exits", ([
		"northup" : __DIR__"doumo",
		"south"   : __DIR__"wanxianlou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 590);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
