// Room: /yangzhou/ershisiqiao.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","��ʮ����");
	set("long",@LONG
��ʮ������������̨������¥������������������Բ�����ʮ�ɣ�
�����һ�ɣ�������̤������ʮ�Ľף�������Χ�Զ�ʮ�ĸ���ʯ���˺�
��ʮ�Ŀ����壬������������Ρ���ͷ��ˮ�����Ժ�ʯ�ѵ�������״��
�����˲��ô�λ�����ַ���ʹ����������ˮ�棬��Բ���ſ���ˮ�е�Ӱ
�ϳ�һ�����¡������̻���ȫ��ˮ��һ·¥ֱ̨��ɽ����ҹ���������ϣ�
��Զ����ԣ����Ӻ��棬�������
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"east" : __DIR__"wangchunlou",
		"west" : __DIR__"pingtai5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 100);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}