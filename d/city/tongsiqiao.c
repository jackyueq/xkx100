// Room: /yangzhou/tongsiqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","ͨ����");
	set("long",@LONG
ͨ�����������ݾɳǵ�����ʮ��ֺ͹��ã���ƽ���������󳵿�
�Բ��С��ŵ���ͷΧ��һ��̳���������ݵ���������ҩ��(shaoyao)��
����һ�����ӣ�����ˮ�ϣ�ز���������ŵĶ�ͷ����һ��ʯ�����顸ͨ
���š������ϳ�����������Ц���������¹���
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"caohexiaojie",
		"east"  : __DIR__"shilijie4",
	]));
	set("item_desc", ([
		"saoyao" : "������ʢ����ҩ���������£��������ԡ����Χ����Ϊ����\n",
	]));
	set("objects", ([
		__DIR__"npc/liuyan" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}