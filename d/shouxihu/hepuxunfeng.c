// Room: /yangzhou/hepuxunfeng.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","����Ѭ��");
	set("long",@LONG
����Ѭ��λ�ڳ��̴���������Ϊ��Ǭ¡����ʹ�ν���������԰����
�ơ���԰����Ǭ¡������Ѳʱ��������԰��԰�����廪�á������ȡ���
������֮�ã����������á�������ݼ�����󡣺�����⣬��Сͤ����
���磬Ƕ������Ѭ�硱���֡��˴�ǰ�����֣����ֺ졢�׺ɻ���������
��С��Ѭ����棬���˺������������������
    ��԰�ڷ��������ɫ���ᣬһƬ��̣���ҫ��ɽ��ÿ��Ϧ�����£�
��������뻭���������Ӧ��
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"north" : __DIR__"siqiaoyanyu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 2);
	set("coor/y", 39);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}