//qiaobi1.c --spe

inherit ROOM;
void create()
{
	set("short","�ͱ���");
	set("long",@LONG
�ͱڰ���У�������ȥ��ƽ̨����ңԶ��������ȥ������
��һ��һľ���ѱ��һ����С�ڵ㡣����ͱڵ״�öֱ࣬��
����ë���Ȼ���㿪ʼ�е���ðȻ������ͱ��ˡ�
LONG
	);
	set("outdoors","jianzhong");
	set("climb_trigger",0);
	set("coor/x", -401);
	set("coor/y", -421);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}