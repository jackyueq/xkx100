// Room: /d/wuxi/shuyuangate.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "��Ժ��¥");
	set("long", @LONG
������Ժ�������ţ������ٺӣ�С����ˮ�������������������š�
һ���ߴ��ʯ�Ʒ�(fang)������ǰ�����ùŰ�ֱ���������������߾���
��Ժ��ѧ�ã�ѧ���ſڹ���һ������(lian)�������Ǳ̱̳�ˮ�����˺�
�پ�������Ŀ��
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shuyuan",
		"south" : __DIR__"eastroad2",
	]));
	set("item_desc", ([
		"lian" : "
  �������������� �������
  ���¹��������� ���¹���\n",
		"fang" : "
 ǰ�̺�ѧ�������Ժ�ѧ����\n",
	]));
	set("coor/x", 390);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

