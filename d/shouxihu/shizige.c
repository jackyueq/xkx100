// Room: /yangzhou/shizige.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ʮ�ָ�");
	set("long",@LONG
ʮ�ָ��Ͼ�������ƽ̨�����磬��ʡ�ʮ�����Σ��߶��㣬�����
�����ϸ����������ߺͱ������ж�ͻ�����Ʊ����������ײ㡢¥�����
��Χ�Լ������佨�����������̨��гһ�¡��ײ������������������
(lian)���ײ��汱���������ҶŸ��������������(lian1)��
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : "
ʤ���ز��ں�ź������������
�������ɿ�����һɫ���µ���
\n",
		"lian1" : "
        ��        ǳ
        ��        ��
        ��        ��
        ��        ��
        ��        ӳ
        ��        ¥
        ��        ̨
\n",
	]));
	set("exits", ([
		"south" : __DIR__"pingtai5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50);
	set("coor/y", 110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}