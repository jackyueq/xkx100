// Room: /d/wuyi/shaibuyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "ɹ����");
	set("long", @LONG
ɹ����λ������Ϫ�ϣ����η��¡����絶�и���һ�㣬ֱ��ֱ�£�
����ƽ̹���߽������ɡ�ÿ��Ϧ�����գ��ұ�ˮˢ�ۼ���������������
����ɹ�����ഫ�������������֯Ů���ƽ���̰ͼ��������������ƽ�
¶ʪ�����ڴ�ɹ�������⵽�����磬����ɹ�����У������ɽ��ƽ�����
ӡҲ�����ұ����ˡ��������������Ʒ塱��
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"jiesunfeng",
		"northeast" : __DIR__"chadong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -4990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

