// Room: /d/heimuya/didao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short","�ص�");
	set("long", @LONG
����һ���쳣�ľ������ȣ��������һ�ţ������ʲô����������
���������棬�㲻���뵽���ƺ���ÿ�����䶼��������ɱ����̫�ֲ��ˣ�
���ܺ�����Ϣ���������һ���붼����������
LONG );

	set("exits",([
		"east"  : __DIR__"didao2",
		"west"  : __DIR__"didao1",
		"south" : __DIR__"didao5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3250);
	set("coor/y", 4210);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}