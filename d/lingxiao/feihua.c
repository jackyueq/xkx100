// Room: /d/lingxiao/feihua.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","�ɻ���");
	set("long",@LONG 
���������ǳ��ŵ��������ӣ�����÷Ů���������ϵľ�����¥����
���󡣻�����������������������Ψһ��Ů�ԣ�һ��Ϊ���ӣ���������
�ϱ�����ϲ�徻����һ�˶����ڴˡ��˴��ǻ�԰С¥֮�ϣ�ƾ��������
ǧ���÷��ӭѩ���裬��÷Ʈ�㣬�׷׶��¡����Ϸ���һ��������ɫ��
÷����
LONG);
	set("exits",([ /* sizeof() == 1 */
		"down"  : __DIR__"huajing",  
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/hua" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8880);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}

