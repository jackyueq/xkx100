// Room: /yangzhou/siqiaoyanyu.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
��������¥λ����������������С��ɽ������������Ϊ���̻�����
������Ϊ��԰���ϰ벿�֡�Ǭ¡��Ѳʱ������Ȥ԰����
    ��������¥������������麣������ȡ���¥Զ�������š������š�
����š����������ſ��ƽ�����ߣ�ȴ�������͸��죬���ȤζȫȻ��
ͬ������ϸ���е�¥Զ��������ͬ������֮�У�������һ����ɴ������
��ã����ɱ�ã��ɵ���������֮��Ȥ��Ǭ¡ÿ���κ�����Ҫ��������
��¥ƾ��������
LONG );
	set("outdoors", "shouxihu");

	set("exits", ([
		"west"  : __DIR__"chunboqiao",
		"south" : __DIR__"hepuxunfeng",
	]));
	set("objects", ([
		"/d/taishan/npc/shu-sheng" : 1,
	]));
	set("coor/x", 2);
	set("coor/y", 40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}