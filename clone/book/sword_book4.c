// sword_book4.c

inherit ITEM;

void create()
{
	set_name("��ɽ����", ({ "sword book", "book" }));
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",
"��������������ħ��ʮ�������Ȼ�ս��ɽ�����ɺ������˴���������
���ɵ���ྫ�����У������ɸ��ֶ��š��������Ἧ���ɲд�����ޣ�
���������ǵõĽ��У����۾��֣�����¼�����������һ�����ס���
��ʮ��������ȥ�ߴ�ݼ�������ɽ��������ֲ���������������������
�ʵ���ʽ��һһ�޸ģ�ʹ�ñ��ɽ������ڰ�·�����·����һʮ��·
���̡�������·����������ȱ��
�ⱾС���Ӿ������������ɽ���ס�\n");
		set("value", 1000);
		set("material", "paper");
		set("skill", ([
			"name"        : "songshan-sword",
			"exp_required": 10000,
			"jing_cost"   : 20,
			"difficulty"  : 20,
			"max_skill"   : 120
		]) );
	}
}
