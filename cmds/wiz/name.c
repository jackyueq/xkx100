// nick.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string name, id ,to,what;
	object obj=me;
	if( !arg ) return notify_fail("ÄãÒªÌæË­È¡Ê²Ã´Ãû×Ö£¿\n");
	if (sscanf(arg, "%s %s(%s)", to,name, id) == 3)
	{
				what="name";
				if (!obj=present(to, environment(me)))
				if (!obj=find_player(to))
							return notify_fail("Ã»ÓÐÕâ¸öÈË¡£\n");
	}
	else if (sscanf(arg,"%s cancel",to)==1)
	{
				what="cancel";
				if (!obj=present(to, environment(me)))
				if (!obj=find_player(to))
							return notify_fail("Ã»ÓÐÕâ¸öÈË¡£\n");
	}
	else if (sscanf(arg,"%s(%s)", name,id)==2)
	{
			 what="name";
	}
	else if (arg=="cancel") 
	{
			what="cancel";
	}
	else
	{
			return notify_fail("Óï·¨¸ñÊ½£ºname [Ä³ÈË] [cancel] [ÖÐÎÄÃû(id)]\n");
	}
	if (what=="cancel")
	{
		if (!obj->query("old_name") || !obj->query("old_id"))
			return notify_fail(obj->query("name")+"²¢Ã»ÓÐÓÃnameÃüÁî¸ÄÃû¹ý¡£\n");
		else
		{
			write("Äã°Ñ "+obj->query("name")+"("+obj->query("id")+") µÄÃû×Ö");
			obj->set("id",obj->query("old_id"));
			obj->set("name",obj->query("old_name"));
			obj->delete("old_id");
			obj->delete("old_name");
			write("»Ö¸´³ÉÁË "+obj->query("name")+"("+obj->query("id")+") ¡£\n");
			return 1;
		}
	}
	else if (what=="name")
	{
	name = replace_string(name, "$BLK$", BLK);
	name = replace_string(name, "$RED$", RED);
	name = replace_string(name, "$GRN$", GRN);
	name = replace_string(name, "$YEL$", YEL);
	name = replace_string(name, "$BLU$", BLU);
	name = replace_string(name, "$MAG$", MAG);
	name = replace_string(name, "$CYN$", CYN);
	name = replace_string(name, "$WHT$", WHT);
	name = replace_string(name, "$HIR$", HIR);
	name = replace_string(name, "$HIG$", HIG);
	name = replace_string(name, "$HIY$", HIY);
	name = replace_string(name, "$HIB$", HIB);
	name = replace_string(name, "$HIM$", HIM);
	name = replace_string(name, "$HIC$", HIC);
	name = replace_string(name, "$HIW$", HIW);
	name = replace_string(name, "$NOR$", NOR);
	id = replace_string(id, "$BLK$", BLK);
	id = replace_string(id, "$RED$", RED);
	id = replace_string(id, "$GRN$", GRN);
	id = replace_string(id, "$YEL$", YEL);
	id = replace_string(id, "$BLU$", BLU);
	id = replace_string(id, "$MAG$", MAG);
	id = replace_string(id, "$CYN$", CYN);
	id = replace_string(id, "$WHT$", WHT);
	id = replace_string(id, "$HIR$", HIR);
	id = replace_string(id, "$HIG$", HIG);
	id = replace_string(id, "$HIY$", HIY);
	id = replace_string(id, "$HIB$", HIB);
	id = replace_string(id, "$HIM$", HIM);
	id = replace_string(id, "$HIC$", HIC);
	id = replace_string(id, "$HIW$", HIW);
	id = replace_string(id, "$NOR$", NOR);

	write("Äã°Ñ "+obj->query("name")+"("+obj->query("id")+") ");	
	obj->set("old_name",obj->query("name"));
	obj->set("old_id",obj->query("id"));
	obj->set("name", name);
	obj->set("id", id);
	write("¸ÄÃûÎª "+obj->query("name")+"("+obj->query("id")+") ¡£\n");
	}
	else 
	{
		write("Äã¿ÉÒÔ¿¼ÂÇÏòÇàÔÆÒªÐ©bug½±Àø¡£\n");
	}
	return 1;
}
int help(object me)
{
	write(@HELP
Ö¸Áî¸ñÊ½ : name Ãû×Ö(id)
           name cancel
           name dami ´óÃ×(dummy)
           name dami cancel
					 
 
ÄãÈç¹ûÏ£ÍûÔÚÃû×ÖÖÐÊ¹ÓÃansiµÄ¿ØÖÆ×ÖÔª¸Ä±äÑÕÉ«£¬¿ÉÒÔÓÃÒÔÏÂµÄ¿ØÖÆ
×Ö´®£º

        $£Â£Ì£Ë$£º[30mºÚÉ«[0m          
        $£Ò£Å£Ä$£º[31mºìÉ«[0m          $£È£É£Ò$£º[1;31mÁÁºìÉ«[0m
        $£Ç£Ò£Î$£º[32mÂÌÉ«[0m          $£È£É£Ç$£º[1;32mÁÁÂÌÉ«[0m
        $£Ù£Å£Ì$£º[33mÍÁ»ÆÉ«[0m        $£È£É£Ù$£º[1;33m»ÆÉ«[0m
        $£Â£Ì£Õ$£º[34mÉîÀ¶É«[0m        $£È£É£Â$£º[1;34mÀ¶É«[0m
        $£Í£Á£Ç$£º[35mÇ³×ÏÉ«[0m        $£È£É£Í$£º[1;35m·ÛºìÉ«[0m
        $£Ã£Ù£Î$£º[36mÀ¶ÂÌÉ«[0m        $£È£É£Ã$£º[1;36mÌìÇàÉ«[0m
        $£×£È£Ô$£º[37mÇ³»ÒÉ«[0m        $£È£É£×$£º[1;37m°×É«[0m
        $£Î£Ï£Ò$£º[0m»Ö¸´Õý³£ÑÕÉ«[0m

HELP
	);
	return 1;
}
