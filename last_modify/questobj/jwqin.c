//jiaowei qin ��β��

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	set_name(HIM"��β��"NOR,({"jiaowei qin","qin"}));
	set_weight(500);
	if(clonep())
		 set_default_object(__FILE__);
	else{
		set("unit","��");
		set("value",0);
		set("material","steel");
		set("long","�ഫ����ǵ�����ļ��ӻ������ȳ��Ľ�ľ���ɵ����٣��ٵ�β���Կɼ�����ɫ��\n");
		set("wield_msg",HIY"$N��������һ��,һ�Ž�β�ٱ��ѳ�����$N����.\n"NOR);
		set("unwield_msg",HIY"$Nʮָһ��������ҷȻ��ֹ��$N����β�٣��Ž����ŵİ����\n"NOR);
		set("unequip_msg",HIY"��ʮָһ��������ҷȻ��ֹ��������β�٣��Ž����ŵİ����.\n"NOR);
	}
	setup();
}

int wield()
{
	object ob = environment();

/*	if (ob && !wizardp(ob)) {
		tell_object(ob, name() + "����ʦ��Ʒ���㲻��ʹ�ã�����������ʦ���棬�������Ը���\n");
		call_out("let_him_die", 300, ob);
		return 0;
	}*/
	return ::wield();
}
/*
void let_him_die(object ob)
{
	if (ob = environment()) {
		ob->add("combat_exp", -30000);
		ob->set_temp("last_damage_from", "������ʦ��Ʒ�ж�");
		ob->die();
	}
}
*/
