// Room: /d/nanshaolin/luohan1
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "�޺���һ��");
	set("long", @LONG
����һ�伫Ϊ��ª���������������ܣ����˼�������⣬���ڿյ�
���ر��������������İڷ��ż��������ҷ��ڵĻƲ����ţ���λ��
�����׵���ɮ�������������Ŀ�붨�������Ǳ���ʮ���޺��������е�
�ط������پ����书�����ڴ������
LONG );
	set("exits", ([
		"north" : __DIR__"luohan2",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/yuanfen" : 1,
	]));
	set("coor/x", 1760);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

