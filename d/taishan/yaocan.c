// Room: /d/taishan/yaocan.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "ң��ͤ");
	set("long", @LONG
����Ϊ���ǰͥ���ɳƲݲ��š��ݲ�ͤ�����˷�������̩ɽ������
���˽��м򵥲ΰݣ������������ͤΪ����Ժ�䡣ǰԺ�������ʱ
���ϼԪ��������Ϊ������Ժ�����念����ʮ����֪̩ͬ��������
���������ֹ��������
����ͤǰʯ�����顰ң��ͤ����������ʨ���ţ���˸�������ǰΪ˫��
�ء�����Ϊͨ��֣��������ƻ�һ�꣬��Ժ�����Ľ�ͤ��
LONG );
	set("exits", ([
		"north" : __DIR__"daimiao",
		"south" : __DIR__"taishanjiao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 450);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
