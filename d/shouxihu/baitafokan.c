// Room: /yangzhou/baitafokan.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","��������");
	set("long",@LONG
�������衣�������Σ�ש��������ƽ̨�ϣ���Ϊ�����۽ǣ������
�ǡ���Ϊ������ש����������ÿ��������裬ÿ���ש��һ��Ф����
������ʮ��ʱ�������������а�Բͻ����������ͳ�������Ļ����ν�
��ͼ���Ӷ�ʹ����ӷ�����������Ȼ����͵ع��ɵ�Բ������������
����ƿ�������пգ��衰�۹��š����ڹ����´�ʿ��
LONG );
	set("exits", ([
		"down" : __DIR__"baitataji",
		"up"   : __DIR__"baitabaosha",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}