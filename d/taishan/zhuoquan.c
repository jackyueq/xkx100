// Room: /d/taishan/zhuoquan.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "��Ȫͤ");
	set("long", @LONG
�Ʋ��Ŷ���Ȫͤ����������ͤ������������������ʯ���۷��٣���
�����ŷþ��ɡ����Ʋ�����Χ�С���ɫȪ���������Ʋ����족��������
�����������������ҡ��������ʮ�ദ���桢�ݡ�����׭���������ͣ�
������Ŀ��
LONG );
	set("exits", ([
		"west" : __DIR__"yunbu",
	]));
	set("outdoors", "taishan");
	set("resource/water", 1);
	set("no_clean_up", 0);
	set("coor/x", 400);
	set("coor/y", 680);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
