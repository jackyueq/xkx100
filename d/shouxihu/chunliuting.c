// Room: /yangzhou/changtichunliu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�����ж��ٺ���һ���밶��ˮ�������˿���ľ������ͤ��ͤ������
���̴������ң���Ϊ�������Ա�������ֱʡ��������������ڡ��ң���
�������������������(lian)���˼�������ҳ��Ԫ���ʾ���ɡ�
LONG );
	set("outdoors", "shouxihu");
	set("no_clean_up", 0);
	set("item_desc", ([
		"lian" : "
        ��        ��
        ��        ��
        ��        �
        ��        Ұ
        ��        ��\n",
	]));

	set("exits", ([
		"south" : __DIR__"changdi1",
		"north" : __DIR__"changdi2",
	]));
	set("coor/x", 0);
	set("coor/y", 32);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}