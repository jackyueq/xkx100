// Room: /d/yanziwu/huafang.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�̰��߽�����һ�����ɳ���ĺ���������ǰΦ�ϸ߹���һյ���
�������е������ߣ�͸�Ž���ˮ���������ÿ����������̨�ϰڷ��ź�
��������ҹ���򣬶���ʮ�������
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"westup" : __DIR__"hongxia1",
	]));
	set("coor/x", 1260);
	set("coor/y", -1250);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}