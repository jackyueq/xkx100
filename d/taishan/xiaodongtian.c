// Room: /d/taishan/xiaodongtian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
���Ź�������ڣ�����С���졣����Ƭʯ�缸������ߣ���Բ��
���˴�һ�����ƣ���Ϫ��̶��ɽ�ֽ��ݣ�ɭɭ���������ж��졣�ϲ�
������֪̩�����¸�Ӧ���⡢�����顰С���족���ȵ׶��²��������
�������Ա�����������������ʯϿ���塣�Ȳ��Բ��������ɫ��ʯ��
�������������ƿ�ľ���֣��Ͽ̡����ġ���
LONG );
	set("exits", ([
		"southwest" : __DIR__"hongmen",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 410);
	set("coor/y", 560);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
